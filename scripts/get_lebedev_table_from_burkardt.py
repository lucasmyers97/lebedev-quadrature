import argparse
import re
import pandas as pd

def get_commandline_args():

    description = ('gets table of Lebedev coordinates and weights from the '
                   'source code from John Burkardt')
    parser = argparse.ArgumentParser(description=description)
    parser.add_argument('--source_filename',
                        help='filename of Lebedev source code')
    parser.add_argument('--output_filename',
                        help='name of file which table will be written to')

    args = parser.parse_args()

    return args.source_filename, args.output_filename



def match_lebedev_functions(file_text):

    # finding everything between `n = 0` and `n = n - 1` lines
    pattern = ('void ld(\d+)'
               ' \( double \*x, double \*y, double \*z, double \*w \)'
               '(?:.|\n)*?(?:n = 0;\n)((?:.|\n)*?)(?:return)')

    matches = re.findall(pattern, file_text)

    return matches



def parse_lebedev_line(function_line):

    gen_oh_pattern = r'gen_oh \( (\d+), .*?\);'
    weight_pattern = r'v = ((?:\d|\.|e|-)+?);'
    a_pattern = r'a = ((?:\d|\.|e|-)+?);'
    b_pattern = r'b = ((?:\d|\.|e|-)+?);'

    gen_oh_match = re.findall(gen_oh_pattern, function_line)
    weight_match = re.findall(weight_pattern, function_line)
    a_match = re.findall(a_pattern, function_line)
    b_match = re.findall(b_pattern, function_line)
    
    if gen_oh_match:
        return 'rule', gen_oh_match[0]
    elif weight_match:
        return 'weight', weight_match[0]
    elif a_match:
        return 'a', a_match[0]
    elif b_match:
        return 'b', b_match[0]
    else:
        return None



def parse_lebedev_function(function_text):

    function_lines = function_text.splitlines()

    generator_point_data_list = []
    generator_point_data = {}
    for function_line in function_lines:
        key_value = parse_lebedev_line(function_line)
        if not key_value:
            continue

        key, value = key_value
        generator_point_data[key] = value
        if key == 'rule':
            generator_point_data_list.append(generator_point_data.copy())

    return generator_point_data_list



def main():

    source_filename, output_filename = get_commandline_args()

    f = open(source_filename)
    file_text = f.read()
    f.close()

    matches = match_lebedev_functions(file_text)
    generator_point_main_dataframe = pd.DataFrame()
    for match in matches:
        generator_point_data_list = parse_lebedev_function( match[1] )
        generator_point_dataframe = pd.DataFrame.from_dict(generator_point_data_list)
        generator_point_dataframe['order'] = match[0].lstrip('0')

        generator_point_main_dataframe = pd.concat([generator_point_main_dataframe, generator_point_dataframe])

    generator_point_main_dataframe.to_csv(output_filename, index=False)

if __name__ == '__main__':
    main()

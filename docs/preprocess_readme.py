import re

def markdown_to_doxygen(text):

    inline_pattern = r'\$(.*?)\$'
    inline_replace = r'\\f$ \1 \\f$'
    block_pattern = r'```math((?:.|\n)*?)```'
    block_replace = r'\\f[ \1 \\f]'

    text = re.sub(inline_pattern, inline_replace, text)
    text = re.sub(block_pattern, block_replace, text, flags=re.MULTILINE)

    text = '@tableofcontents\n\n' + text

    link_pattern = r'\((.*)\/README\.md\)'
    link_replace = lambda m: r'(' + m.group(1).upper() + r'_README.md' + r')'
    text = re.sub(link_pattern, link_replace, text)

    return text



def main():

    input_filenames = ['../README.md', '../src/README.md', '../test/README.md']
    output_filenames = ['README.md', 'SRC_README.md', 'TEST_README.md']
    
    file_text = []
    for filename in input_filenames:
        with open(filename) as f:
            text = f.read()
        
        file_text.append( markdown_to_doxygen(text) )

    for text, filename in zip(file_text, output_filenames):
        with open(filename, 'w') as f:
            f.write(text)



if __name__ == '__main__':
    main()

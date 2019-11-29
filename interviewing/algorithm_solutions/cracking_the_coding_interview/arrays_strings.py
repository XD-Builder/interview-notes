"""
This class provides solutions to arrays and strings questions
"""


def is_unique(str1):
    """
    Determine if a string has all unique characters
    """
    char_map = {}
    for i in str1:
        if char_map.get(i) is None:
            char_map[i] = True
        else:
            return False
    return True


def is_unique_test():
    """
    Test isUnique works for unique and non-unique strings
    """
    assert is_unique("aa") is False
    assert is_unique("abcs123") is True
    assert is_unique("abcABDs123") is True


def check_permutation(str1, str2):
    """
    Given two strings, write a method to decide if one
    is a permutation of the other, assuming case sensitive
    """
    str_map = {}
    if len(str1) != len(str2):
        return False

    for i in str1:
        if str_map.get(i) is None:
            str_map[i] = 1
        else:
            str_map[i] += 1
    for i in str2:
        if str_map.get(i) is None:
            return False
        str_map[i] -= 1

    for i in str_map:
        if str_map[i] != 0:
            return False
    return True


def check_permutation_test():
    """
    test check permutation
    """
    assert check_permutation("God", "dog") is False
    assert check_permutation("god", "dog") is True
    assert check_permutation("god ", "dog") is False


def urlify(str1):
    """
    A method to replace all spaces in a string with '%20'.

    """
    return "%20".join(str1.split(" "))


def urlify_test():
    """
    test urlify
    """
    assert urlify("Hello World") == "Hello%20World"
    assert urlify("Hello  World  ") == "Hello%20%20World%20%20"


def palindrome_permutation(str1):
    """
    Check if a string is a permutation
    """
    str_map = {}
    for i in str1.lower():
        if i == ' ':
            continue
        if str_map.get(i) is None:
            str_map[i] = 1
        else:
            str_map[i] += 1

    num_1s = 0
    for i in str_map:
        if str_map[i] % 2 == 1:
            num_1s += 1
    return not num_1s > 1


def palindrome_permutation_test():
    """
    check if palindrome
    """
    assert palindrome_permutation("Tact Coa") is True


def one_away(str1, str2):
    """
    Three types of edits that can be performed on strings:
    Insert a character, remove a character, or replace
    a character. Given two strings, check if they are
    one edit (or zero edits) away.
    """
    num_edits = 0
    str2_offset = 0
    str1_offset = 0
    if abs(len(str1) - len(str2)) > 1:
        return False

    for i, _ in enumerate(str1, 0):
        if num_edits == 0 and i+1 == len(str1):
            return True
        if num_edits > 1:
            return False
        if str1[i + str1_offset] != str2[i + str2_offset]:
            # Remove
            if len(str1) > len(str2):
                str2_offset -= 1
            elif len(str2) > len(str1):
                str1_offset -= 1
            num_edits += 1
    return num_edits < 2


def one_away_test():
    """
    Test one_away
    """
    assert one_away("pale", "ple") is True
    assert one_away("ple", "pale") is True
    assert one_away("pales", "pale") is True
    assert one_away("pale", "bale") is True
    assert one_away("pale", "bake") is False
    assert one_away("pale", "bakee") is False


def string_compression(str1):
    """ Perform basic string compression using the counts
    of repeated characters. If compression is bigger than
    original string, then return the original string

    :arg1: str1
    :returns: compressed_str

    """
    char = ''
    char_count = 0
    char_array = []
    for i in str1:
        if i != char:
            if char_count > 0:
                char_array.append(char + str(char_count))
            char = i
            char_count = 1
        else:
            char_count += 1
    char_array.append(char + str(char_count))

    compressed_str1 = "".join(char_array)
    return str1 if len(str1) < len(compressed_str1) else compressed_str1


def string_compression_test():
    """Test compression
    """
    assert string_compression("abbccc") == "a1b2c3"
    assert string_compression("abcccc") == "a1b1c4"
    assert string_compression("abcc") == "abcc"
    assert string_compression("abccc") == "abccc"


def rotate_matrix(matrix):
    """Given an image represented by an NxN matrix, where each
    pixel in the image is 4 bytes, write a method to rotate the image
    by 90 degrees

    """
    n = len(matrix)
    for i in range(n // 2):
        lastIndexI = n-i-1
        for j in range(i, lastIndexI):
            lastIndexJ = lastIndexI - j + i
            top_ij = matrix[i][j]
            matrix[i][j] = matrix[j][lastIndexI]
            matrix[j][lastIndexI] = matrix[lastIndexI][lastIndexJ]
            matrix[lastIndexI][lastIndexJ] = matrix[lastIndexJ][i]
            matrix[lastIndexJ][i] = top_ij
    return matrix


def rotate_matrix_test():
    """
    from [ 1,2,3
           1,2,3
           1,2,3 ]
    to   [ 3,3,3,
           2,2,2,
           1,1,1 ]
    """
    w, h = 2, 2
    matrix = [[i+1 for i in range(w)] for y in range(h)]
    matrix_trans = [[h - y for i in range(w)] for y in range(h)]
    assert rotate_matrix(matrix) == matrix_trans

    w, h = 3, 3
    matrix = [[i+1 for i in range(w)] for y in range(h)]
    matrix_trans = [[h - y for i in range(w)] for y in range(h)]
    assert rotate_matrix(matrix) == matrix_trans


def zero_matrix(matrix):
    """If an element in an MxN matrix is 0
    then the entire row and column are set to 0

    :arg1: MxN matrix
    :returns: transformed matrix

    """
    zrows = [0] * len(matrix)
    zcols = [0] * len(matrix[0])

    for i in range(len(zrows)):
        for j in range(len(zcols)):
            if matrix[i][j] == 0:
                zrows[i] = 1
                zcols[j] = 1

    for i in range(len(zrows)):
        if zrows[i] == 1:
            matrix[i] = [0] * len(zcols)

    for i in range(len(zcols)):
        if zcols[i] == 1:
            for j in range(len(zrows)):
                matrix[j][i] = 0

    return matrix


def zero_matrix_test():
    """test zero_matrix creates zero matrix
    """
    matrix = []
    matrix.append([1, 2, 3, 0])
    matrix.append([1, 0, 3, 1])
    matrix.append([1, 3, 0, 1])
    assert zero_matrix(matrix) == [[0]*4 for i in range(3)]

    matrix = []
    matrix.append([1, 2, 3, 0])
    matrix.append([1, 0, 3, 1])
    matrix.append([1, 3, 2, 1])
    expected = [[0]*4 for i in range(2)]
    expected.append([1, 0, 2, 0])
    assert zero_matrix(matrix) == expected


def string_rotation(s1, s2):
    """Check s2 is a rotation of s1.
    s1 can be "helloworld"
    s2 can be "orldhellow"

    :arg1: TODO
    :returns: TODO

    """
    return s2 in s1+s1


def string_rotation_test():
    assert string_rotation("helloworld", "orldhellow")
    assert string_rotation("helloworld", "orlhellow") is False
# zero_matrix_test()
# rotate_matrix_test()
# string_compression_test()
# one_away_test()
# is_unique_test()
# check_permutation_test()
# urlify_test()
# palindrome_permutation_test()

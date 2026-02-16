def reversewords(s):
    l = s.split(' ')
    new_str = ''
    for i in l[::-1]:
        new_str += i
        new_str += ' '
    return new_str
print(reversewords('the sky is blue'))
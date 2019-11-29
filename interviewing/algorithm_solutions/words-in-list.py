# def matchWordsInDictParent(w, l):
#     map = {}
#     for i in l:
#         if map.get(len(i)):
#             map[len(i)].append(i)
#         else:
#             map[len(i)] = [i]
#     return matchWordsInDict(w, map, 0)


# def matchWordsInDict(w, m, s):
#     for k, v in m.items():
#         for i in v:
#             if (s+k) > len(w):
#                 continue
#             if w[s:s+k] == i and (s+k) == len(w):
#                 return w[s:s+k]
#             elif w[s:s+k] == i:
#                 word = matchWordsInDict(w,m,s+k)
#                 if word == "":
#                     continue
#                 else:
#                     return w[s:s+k] + " " + word
#     return ""
# print(matchWordsInDictParent("applepiepiepieappapple", ["app", "app", "apple", "pie"]))


# Given a string of words and a list of words as a dictionary
# return words separated by space if the string of words can be matched to words in the dictionary
# Else return ""

def matchWordsInDict(w, l, s):
    # iterate over the list of words, and recursively call this function if there is a match found
    # with the starting index defined in s.
    for v in l:

        # Make sure we don't get index out of bound
        k = len(v)
        if (s+k) > len(w):
            continue
        if w[s:s+k] == v:
            # If the word matches and it's the last word, return the last word
            # This is the end condition for the recursive call
            if (s+k) == len(w):
                return w[s:s+k]
            else:
                # the word matches, go find the next match in dict
                # if it doesn't match, go to the next word in dict
                # else return the words that matched in that recursive call
                word = matchWordsInDict(w,l,s+k)
                if word == "":
                    continue
                else:
                    return w[s:s+k] + " " + word
    return ""

print(matchWordsInDict("applepiepiepieappapple", ["app", "app", "apple", "pie"], 0))

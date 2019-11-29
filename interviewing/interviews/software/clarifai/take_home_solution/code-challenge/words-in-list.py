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

def matchWordsInDict(w, l, s):
    for v in l:
        k = len(v)
        if (s+k) > len(w):
            continue
        if w[s:s+k] == v and (s+k) == len(w):
            return w[s:s+k]
        elif w[s:s+k] == v:
            word = matchWordsInDict(w,l,s+k)
            if word == "":
                continue
            else:
                return w[s:s+k] + " " + word        
    return ""

print(matchWordsInDict("applepiepiepieappapple", ["app", "app", "apple", "pie"], 0))
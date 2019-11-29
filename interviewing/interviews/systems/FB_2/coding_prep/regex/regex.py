import re

# Simple match
p = re.compile('[a-z]+')
print(p.match("a").span())

# Simple Search, skips first few characters
p = re.compile('[a-z]+')
print(p.search("::: message").span())

# Simple split with max split of 2
p = re.compile(r'\W')
print(p.split("Split this word", 1))

# Simple search and replace all occurrences
p = re.compile('(red|yellow|green)')
print(p.sub("dark", "red car, green grass, yellow fox"))

# Simple named group search
p = re.compile(r'(?P<word>\b\w+\b)')
m = p.search('(((( Lots of punctuation )))')
print(m.group('word'))
print(m.group(1))
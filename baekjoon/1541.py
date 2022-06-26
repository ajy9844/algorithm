exp = input()
tokens = exp.split('-')

for i in range(len(tokens)):
  operands = map(int, tokens[i].split('+'))
  tokens[i] = sum(operands)

ans = tokens[0]
for i in range(1,len(tokens)):
  ans -= tokens[i]

print(ans)

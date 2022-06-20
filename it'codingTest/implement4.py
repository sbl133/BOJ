s = list(input())
s = sorted(s)
sum = 0;
count = 0;
for i in s:
  if i >= '1' and i <= '9':
    sum += int(i)
    count += 1

s = s[count:]
if sum != 0:
  s.append(str(sum))
print("".join(s))
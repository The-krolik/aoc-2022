f = open("input.txt")
totals = []
grand_total = 0

sum_cal = 0
for line in f:
    if line != "\n":
        sum_cal += int(line)
    else:
        totals.append(sum_cal)
        sum_cal = 0

val = max(totals)
index = totals.index(val)
print(f"max is {val} at index {index}")
grand_total += val

totals.pop(index)
val = max(totals)
index = totals.index(val)
print(f"next highest is {val} at index {index}")
grand_total += val

totals.pop(index)
val = max(totals)
index = totals.index(val)
print(f"next highest is {val} at index {index}")
grand_total += val

print(f"grand total is {grand_total}")

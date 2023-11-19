t = int(input())

primer = "99 bottles of beer on the wall, 99 bottles of beer."
six_lines = """99 bottles of beer on the wall, 99 bottles of beer.Take one down and pass it around, 98 bottles of beer on the wall.98 bottles of beer on the wall, 98 bottles of beer.Take one down and pass it around, 97 bottles of beer on the wall.97 bottles of beer on the wall, 97 bottles of beer.Take one down and pass it around, 96 bottles of beer on the wall."""
hw = "Hello, world!"

def solve():

    x = int(input())
    lines = []
    for _ in range(x):
        lines.append(input())

    count = 0
    code = ""
    quines = set()
    while count < x:
        line = lines[count]

        if line == primer:

            if x - count < 5:
                print("IMPOSSIBLE")
                return

            count+=1
            for _ in range(5):
                line += lines[count]
                count += 1

            if line != six_lines:
                print("IMPOSSIBLE")
                return
            code += "9"

        elif line == hw:
            code += "H"
            count += 1
        else:
            code += "Q"
            quines.add(line)
            count += 1
    
    if len(set(quines)) > 1:
        print("IMPOSSIBLE")
    elif len(set(quines)) ==1:
        quine = list(quines)[0].replace("+", "")
        if quine != code:
            print("IMPOSSIBLE")
        else:
            print(list(quines)[0])
    else:
        print(code)


        

for _ in range(t):
    solve()


from re import A


def testVoid():
    a = 3
    with open("tett.json", "w") as file:
        pass
    

b = testVoid()
print(b)

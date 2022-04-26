## User -> [
# 1. Get current time
# 2. Get favourite number
# 3. Define favourite number
# 4. Exit

## User -> 1. -> Program finished -> Ask for next input -> Loop
from scripts.getTimeJojo import getTime

favNumber = ""
while True:
    print("----------------------------------------------")
    print(
        "1. Get current time\n2. Get favourite number \n3. Define favourite number \n4. Exit"
    )
    value = input("Please select one:\n")

    print(f"You entered {value}")
    if value == "1":
        currentTime = getTime()
        print(currentTime)
    elif value == "2":
        if favNumber == "":
            print("You have not set favourite number!")
        else:
            print(f"Your favourite number is {favNumber}")
    elif value == "3":
        favNumber = input("Please enter your favourite number:\n")
    elif value == "4":
        break

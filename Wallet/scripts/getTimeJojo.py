from datetime import datetime
import json


def getTime():
    now = datetime.now()
    current_time = now.strftime("%H:%M:%S")
    return current_time
    ###print("Current Time is :", current_time)

    ##jsonString = json.dump(current_time)
    with open("test.json", "w") as file:
        file.write(current_time)

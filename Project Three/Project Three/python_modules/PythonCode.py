#//
#//
#//PythonCode.py
#//
#//Date: October 10, 2022
#//Name: Christopher Sharp
#//
#//




# global dictionary to hold data from file
items = {}

# looked up code help from IT-140 ZyBooks
# Reading file and iterating over contents and adding them to python dictionary for easier access with keys
def OpenReadFile():
    
    with open("GroceryList.txt", 'r') as file:

        fileInformation = file.readlines()

        for ln in fileInformation:
            itemNum = ln.strip()

            if itemNum not in items.keys():
                items[itemNum] = 0
                
            items[itemNum] += 1
    
    return items

# getting and printing dictionary 
def ItemHistory():
   
    groceryList = OpenReadFile()

    for key, value in sorted(groceryList.items(), key = lambda x:x[1], reverse = True):
        print(key, value)

# search through dictionary using keys entered by user then returning value
def ItemFrequency(name):
    name = name.capitalize()
    groceryList = OpenReadFile()

    if name not in groceryList.keys():
        return 0
    else:
        return items[name]
   
# writing dat file from dictionary 
def WriteDatFile():
    groceryList = OpenReadFile()

    with open("frequency.dat", 'w') as file:
        for key, value in sorted(groceryList.items(), key = lambda x:x[1], reverse = True):
            print(key, value, file=file)

        



   






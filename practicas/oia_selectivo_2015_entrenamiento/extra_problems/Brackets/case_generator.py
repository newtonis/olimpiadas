import random

def main():
    casos = 200
    file = open("input2.in","w+")
    file.write(str(casos)+"\n")
    for x in range(casos):
       file.write(str(30000)+"\n")
       word = ""
       for y in range(30000):
           v = random.randrange(2)
           if v == 0:
               word += "("
           else:
               word += ")"
       file.write(word+"\n")
       file.write(str(100)+"\n")
       for y in range(100):
           v = random.randrange(4)
           if (v == 0):
               file.write("0"+"\n")
           else:
               vv = random.randrange(30000)
               file.write(str(vv)+"\n")
        

if __name__ == "__main__":
    main()

# By Fabio Kepler
# run: (python3 arabic2roman.py)


roman_numerals = {0: {1: 'I', 5: 'V'},
                  1: {1: 'X', 5: 'L'},
                  2: {1: 'C', 5: 'D'},
                  3: {1: 'M'}} 

def main():
    while True:
        arabic = input("Número (inteiro) arábico: ")
        if not arabic: return
        try:
            arabic_int = int(arabic)
            if arabic_int > 3999: continue
        except ValueError:
            print("Número inválido")
            continue
        arab_str = reversed(arabic)
        roman_str = ""

        count = 0


        for i, char in enumerate(arab_str):
            algarism = int(char)

            count += 1
            	
            while algarism > 0:
                if algarism == 4:
                    algarism = 0
                    roman_str = roman_numerals[i][1] + roman_numerals[i][5] + roman_str
                elif algarism == 9:
                    algarism = 0
                    roman_str = roman_numerals[i][1] + roman_numerals[i+1][1] + roman_str
                elif algarism == 5:
                    algarism -= 5
                    roman_str = roman_numerals[i][5] + roman_str
                else:
                    algarism -= 1
                    roman_str = roman_numerals[i][1] + roman_str

                count += 1

        print("Número romano: {}".format(roman_str))
        print("iters final %s\n" %(count))

if __name__ == "__main__":
    print("Conversor de números arábicos para romanos")
    main()


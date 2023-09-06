import random
import string
print('Welcome to the password generator')
number_letters = int(input('How many letters do u want to input? '))
number_numbers = int(input('How many numbers do u want to input? '))
number_symbols = int(input('How many symbols do u want to input? '))

letters = list(string.ascii_letters)
numbers = [str(i) for i in range(10)]
symbols = ['!', '#', '$', '%', '&', '(', ')', '*', '+']

password_list = []
for x in range(0, number_letters):
    password_list += random.choice(letters)
for x in range(0, number_numbers):
    password_list += random.choice((numbers))
for x in range(0, number_symbols):
    password_list += random.choice((symbols))

password = random.shuffle(password_list)
password = ""
for y in password_list:
    password += y

print(password)
a=open("input", 'r').read()

a=a.split()

pref = 'unsigned char shellcode[] = '
#print(a)
a[4]=a[4][:-1]
for i in range(5, len(a)):
    a[i]=a[i][1:-1]
a=a[4:]


a=''.join(a)
print(pref+a)

#for i in range(len(a)):



'''
a=bytearray(a)
print(a)
a=a.split()
a=a[4:]

print(a)

for element in a:
    print(len(element))
#for byte in a[4]:


head = 'unsigned char shellcode[] = '

'''
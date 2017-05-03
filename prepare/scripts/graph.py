import os
import matplotlib.pyplot as plt

def savePic(name='', fmt='png'):
    pwd = os.getcwd()
    os.chdir('./pictures/')
    plt.savefig('%s.%s' % (name, fmt), fmt='png')
    os.chdir(pwd)

nlist = sorted(classes, key=lambda item: item[0])
fig = plt.figure()
# for n in classes[1:]:
#     plt.scatter(n[0], n[1])
# plt.plot(map(lambda item: (item[1], item[0]), classes))
# v = [item[1] for item in classes[1:]]
plt.hist([item[0] for item in nlist])
plt.grid(True)
# savePic(name='pic1', fmt='png')
# plt.show()

for i in nlist:
    print(i[0], i[1])

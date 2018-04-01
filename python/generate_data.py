import numpy as np

def make_list(name, n):
    s = np.random.random_sample((n,)) - 0.5
    f = open(name, 'w')
    f.write(str(int(n))+'\n')
    for i in range(n):
        f.write(str(s[i])+'\n')
    f.close()

if __name__ == "__main__":
    lists = [1E1,1E2,1E3,1E4,1E5]
    names = ['1E1','1E2','1E3','1E4','1E5']

    for n,name in zip(lists,names):
        make_list(name+'.list', int(n))

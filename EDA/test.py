def insert_sort(a):
    for i in range(0,len(a)):
        cur_value=a[i]
        j=i-1
        while j>=0 and a[j] > cur_value:
            a[j+1]=a[j]
            j=j-1
        a[j+1]=cur_value
    return a


def merge_sort(a):
    a=list(a)
    for i in range(0,len(a)):
        a[i]=[int(a[i])]
    while len(a)>1:
        for i in range(0,int(np.floor(len(a)/2))):
            lista=[]
            while len(a[i])!=0 and len(a[i+1])!=0:
                if a[i][0]<=a[i+1][0]:
                    lista.append(a[i][0])
                    a[i].pop(0)
                else:
                    lista.append(a[i+1][0])
                    a[i+1].pop(0)
            if len(a[i])==0:
                lista=lista+a[i+1]
            else:
                lista=lista+a[i]
            a.pop(i+1)
            a[i]=lista
    return a[0]


def is_sorted(a):
    for i in range(0,len(a)-1):
        if a[i]>a[i+1]:
            return False
    return True

def main():
    global y11,y12,y21,y22,y31,y32
    y11,y12,y21,y22,y31,y32=[],[],[],[],[],[]
    ns = np.linspace(10000, 100000, 10)
    #RANDOM CASE
    for n in ns:
        a=np.random.randint(0,1000000,int(n))
        begin = time.time()
        sorted_a = list(insert_sort(a))
        end = time.time()
        t1=end-begin
        if not is_sorted(sorted_a):
            print("ERROR")
        begin = time.time()
        sorted_a = list(merge_sort(a))
        end = time.time()
        t2=end-begin
        if not is_sorted(sorted_a):
            print("ERROR")
        y11.append(t1)
        y12.append(t2)
        print('RANDOM CASE -',n,'ELEMENTS')
    y11=np.array(y11)
    y12=np.array(y12)
    #BEST CASE
    for n in ns:
        a=np.arange(int(n))
        begin = time.time()
        sorted_a = list(insert_sort(a))
        end = time.time()
        t1=end-begin
        if not is_sorted(sorted_a):
            print("ERROR")
        begin = time.time()
        sorted_a = list(merge_sort(a))
        end = time.time()
        t2=end-begin
        if not is_sorted(sorted_a):
            print("ERROR")
        y21.append(t1)
        y22.append(t2)
        print('BEST CASE -',n,'ELEMENTS')
    y21=np.array(y21)
    y22=np.array(y22)
    #WORST CASE
    for n in ns:
        a=np.arange(int(n))
        a = a[::-1]
        begin = time.time()
        sorted_a = list(insert_sort(a))
        end = time.time()
        t1=end-begin
        if not is_sorted(sorted_a):
            print("ERROR")
        begin = time.time()
        sorted_a = list(merge_sort(a))
        end = time.time()
        t2=end-begin
        if not is_sorted(sorted_a):
            print("ERROR")
        y31.append(t1)
        y32.append(t2)
        print('WORST CASE -',n,'ELEMENTS')        
    y31=np.array(y31)
    y32=np.array(y32)

if __name__ == "__main__":
    main()
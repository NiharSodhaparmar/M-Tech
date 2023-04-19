def lamport_compare(time1,time2):
    return max(time1 , time2) + 1


P = {1:{}, 2:{}, 3:{}} # Inititalized an empty dictionary having 3 process

inc = 0

n1 = int(input("Enter the no. of events in Process 1 : "))
e1 = [i for i in range(1, n1 + 1)]
P[1] = {key: key for key in e1}
print(P[1])
print("\n")

n2 = int(input("Enter the no. of events in Process 2 : "))
e2 = [i for i in range(1, n2 + 1)]
P[2] = {key:key for key in e2}
print(P[2])
print("\n")

n3 = int(input("Enter the no. of events in Process 3 : "))
e3 = [i for i in range(1, n3 + 1)]
P[3] = {key:key for key in e3}
print(P[3])
print("\n")

comm = int(input("Enter the no of communication lines : "))
print("\n")

while inc < comm:
    sent = int(input("Enter the sending process number : "))
    recv = int(input("Enter the receiving process number : "))
    sent_event_no = int(input("Enter the sending event number : "))
    recv_event_no = int(input("Enter the receiving event number : "))
    if sent <= 3 and recv <= 3:
        print ("P{} --> P{}".format(sent,recv))
        if (recv_event_no-1)<=0:
            P[recv][recv_event_no] = lamport_compare(P[sent][sent_event_no],0)
        else:
            P[recv][recv_event_no] = lamport_compare(P[sent][sent_event_no],P[recv][recv_event_no-1])
        print ("New lamport value of \"event {}\"  in process P{} is : {} \n".format(recv_event_no,recv,P[recv][recv_event_no]))
        
        # Changing vector for next events.
        if (recv_event_no + 1) in P[recv]:
            for i in range(recv_event_no + 1, len(P[recv]) + 1):
                P[recv][i] = P[recv][i-1] + 1
    else:
        print ("Enter the sent/recv within existing process")
    inc += 1

print("Final lamport timestamps of the 3 process are")
print(P[1])
print(P[2])
print(P[3])

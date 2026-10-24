class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
         //  now hamee day nikaalnaa haii taaki range pata kar sakee

        int days[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int AlicearrivalMM=stoi(arriveAlice.substr(0,2));
     int AlicearrivalDD=stoi(arriveAlice.substr(3,2));
     int AliceleaveMM=stoi(leaveAlice.substr(0,2));
     int AliceleaveDD=stoi(leaveAlice.substr(3,2));
     int bobarrivalMM=stoi(arriveBob.substr(0,2));
     int bobarrivalDD=stoi(arriveBob.substr(3,2));
     int bobleaveMM=stoi(leaveBob.substr(0,2));
     int bobleaveDD=stoi(leaveBob.substr(3,2)); 
int srof_alice=0; //starting range of alice
for(int i=0;i<AlicearrivalMM-1;i++){
srof_alice+=days[i];
}
srof_alice+=AlicearrivalDD; 
//ending range of alice
int erof_alice=0;
for(int i=0;i<AliceleaveMM-1;i++){
erof_alice+=days[i];
}
erof_alice+=AliceleaveDD;

int srof_bob=0; //starting range of bob
for(int i=0;i<bobarrivalMM-1;i++){
srof_bob+=days[i];
}
srof_bob+=bobarrivalDD; 
//ending range of bob
int erof_bob=0;
for(int i=0;i<bobleaveMM-1;i++){
erof_bob+=days[i];
}
erof_bob+=bobleaveDD;
int l=max(srof_alice,srof_bob);
int r=min(erof_alice,erof_bob);
if(l>r) return 0;
return r-l+1;
}
};
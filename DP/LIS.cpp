int LIS(int arr[],int n){
    vector<int> V;
    for(int i=0;i<n;i++){
        auto it=lower_bound(V.begin(),V.end(),arr[i]);
        if(V.end()==it) V.push_back(arr[i]);
        else V[it-V.begin()]=arr[i];
    }
    return V.size();
}
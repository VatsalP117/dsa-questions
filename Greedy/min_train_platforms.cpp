//link: https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#
//my solution (brute)
int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	vector<int> platforms;
    	int num=0;
    	vector<pair<int,int>> trains;
    	for(int i=0;i<n;i++){
    	    trains.push_back({arr[i],dep[i]});
    	}
    	sort(trains.begin(),trains.end());
    	for(int i=0;i<n;i++){
    	    if(num==0){
    	        platforms.push_back(trains[i].second);
    	        num++;
    	        continue;
    	    }
    	    bool flag=false;
    	    for(int j=0;j<platforms.size();j++){
    	        if(platforms[j]<trains[i].first){
    	            flag=true;
    	            platforms[j]=trains[i].second;
    	            break;
    	        }
    	        
    	    }
    	    if(flag==false){
    	        platforms.push_back(trains[i].second);
    	        num++;
    	    }
    	}
    	return num;
    }
#include <stdio.h>
#include <stdlib.h>
#include "Headers.h"
int subarraySum(int* nums, int n, int k) {
        int sum[n+1];
        sum[0]=0;
        sum[1]=nums[0];
        for (int i=1;i<n;i++){ 
            sum[i+1]=sum[i]+nums[i];
        }
        int res=0;
        for(int i=0;i<n+1;i++){
            for(int j=0;j<i;j++){
                if(sum[i]-sum[j]==k){
                    res++;
                }
            }
        }
        return res;
}
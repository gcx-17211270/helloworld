//我觉得这题本意应该是考察链表的操作，但是吧，我弄了个大数组，结果也AC了

#define Max_Tweet_Size 20000
#define Max_User_Id 1000

typedef struct 
{
    int m_post_tweet_nums;
    int m_user_nums[Max_User_Id];
    int m_user_follwer_nums[Max_User_Id];
    int m_post_tweet[Max_Tweet_Size][2];
    int m_user_follwer[Max_User_Id][Max_User_Id];
} Twitter;

/** Initialize your data structure here. */

Twitter* twitterCreate() 
{
    Twitter *obj;

    obj=(Twitter*)malloc(sizeof(Twitter));

    obj->m_post_tweet_nums=0;

    for(int i=0;i<Max_User_Id;i++)
    {
        obj->m_user_follwer_nums[i]=0;
        obj->m_user_nums[i]=0;
    }

    return obj;
}

/** Compose a new tweet. */
void twitterPostTweet(Twitter* obj, int userId, int tweetId) 
{
    if(obj->m_post_tweet_nums<Max_Tweet_Size)
    {
        obj->m_post_tweet[obj->m_post_tweet_nums][0]=userId;
        obj->m_post_tweet[obj->m_post_tweet_nums][1]=tweetId;
        obj->m_post_tweet_nums++;
    }
}

/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
int* twitterGetNewsFeed(Twitter* obj, int userId, int* retSize) 
{
    int *ret,k=0;

    ret=(int *)malloc(sizeof(int)*10);

    //printf("obj->m_post_tweet_nums=%d \n",obj->m_post_tweet_nums);

    for(int i=obj->m_post_tweet_nums-1;i>=0&&k<10&&i<Max_Tweet_Size;i--)
    {
        //printf("obj->m_post_tweet[i][0]=%d obj->m_post_tweet[i][1]=%d \n",obj->m_post_tweet[i][0],obj->m_post_tweet[i][1]);
        if(obj->m_post_tweet[i][0]==userId)
        {
            ret[k++]=obj->m_post_tweet[i][1];
        }
        else
        {
            for(int j=0;j<obj->m_user_follwer_nums[userId]&&k<10&&j<Max_User_Id;j++)
            {
                if(obj->m_user_follwer[userId][j]==obj->m_post_tweet[i][0])
                {
                    ret[k++]=obj->m_post_tweet[i][1];
                    break;
                }
            }
        }
    }

    *retSize=k;
    return ret;
}

/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
void twitterFollow(Twitter* obj, int followerId, int followeeId) 
{
    for(int i=0;i<obj->m_user_follwer_nums[followerId];i++)
    {
        if(obj->m_user_follwer[followerId][i]==followeeId)
        {
            return ;
        }
    }

    obj->m_user_follwer[followerId][obj->m_user_follwer_nums[followerId]]=followeeId;
    obj->m_user_follwer_nums[followerId]++;
}

/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
void twitterUnfollow(Twitter* obj, int followerId, int followeeId) 
{
      for(int i=0;i<obj->m_user_follwer_nums[followerId];i++)
    {
        if(obj->m_user_follwer[followerId][i]==followeeId)
        {
            for(int j=i+1;j<obj->m_user_follwer_nums[followerId];j++)
            {
                obj->m_user_follwer[followerId][j-1]=obj->m_user_follwer[followerId][j];
            }
            obj->m_user_follwer_nums[followerId]--;
            return ;
        }
    }
}

void twitterFree(Twitter* obj) 
{
    free(obj);
}

/**
 * Your Twitter struct will be instantiated and called as such:
 * Twitter* obj = twitterCreate();
 * twitterPostTweet(obj, userId, tweetId);
 
 * int* param_2 = twitterGetNewsFeed(obj, userId, retSize);
 
 * twitterFollow(obj, followerId, followeeId);
 
 * twitterUnfollow(obj, followerId, followeeId);
 
 * twitterFree(obj);
*/

/*
作者：yxyy3604
链接：https://leetcode-cn.com/problems/design-twitter/solution/355-she-ji-tui-te-qi-shi-ba-jian-ge-da-shu-zu-ye-n/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
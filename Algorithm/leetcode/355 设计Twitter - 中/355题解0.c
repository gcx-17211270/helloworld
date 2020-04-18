#define NULL 0
typedef struct _followee_t {
    int id;
    struct _followee_t *next;
} FOLLOWEE;

typedef struct _user_info_t {
    int id;
    FOLLOWEE followee;      //关注的人的id列表
    struct _user_info_t *next;
} USER;

typedef struct _news_list_t {
    int userid;
    int twtid;
    struct _news_list_t *next;
} NEWS;
typedef struct {
    USER *usrlst;
    USER *usrtail;
    NEWS *newslst;
    NEWS *newstial;
} Twitter;

/** Initialize your data structure here. */

Twitter* twitterCreate() {
    Twitter* new = (Twitter*)malloc(sizeof(Twitter));
    memset(new, 0, sizeof(Twitter));    //?
    return new;
}

/** Compose a new tweet. */
void twitterPostTweet(Twitter* obj, int userId, int tweetId) {
  NEWS* news = (NEWS*)malloc(sizeof(NEWS));
  news->userid = userId;
  news->twtid = tweetId;
  news->next = obj->newslst->next;
  obj->newslst->next = news;
}

/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
int* twitterGetNewsFeed(Twitter* obj, int userId, int* retSize) {
  USER* me = findUserById(obj, userId);
  int* tweets = (int*)malloc(4 * 10);
  int idx = 0;
  NEWS* news = obj->newslst;
  while (news) {
      if (findFollowee(me, userId, news->userid) == 1){
          tweets[idx++] = news->twtid;
      }
      if (idx >= 10) break;
      news = news->next;
  }
  *retSize = idx;
  return tweets;
}

/*******************上面使用到的函数0*********************/
USER* findUserById(Twitter* obj, int userId)
{
    USER *usr = obj->usrlst;
    while (usr) {
        if (usr->id == userId){
            return usr;
        }
        usr = usr->next;
    }
    return NULL;
}
int findFollowee(USER *usr, int userId, int followeeid)
{
    if (userId == followeeid) return 1;
    if (usr == NULL) return 0;
    FOLLOWEE *find = usr->followee.next;
    if (usr->id == followeeid) return 1;
}
/*******************使用到的函数0结束*********************/

/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
void twitterFollow(Twitter* obj, int followerId, int followeeId) {
    USER* follower = obj->newslst;
    if (follower == NULL) {
        addNewUser(obj, NULL, followerId, followeeId);
        return;
    }
    while (follower->next != NULL) {
        if (follower->id == followerId) {
            break;
        }
        follower = follower->next;
    }
    if (follower->id == followerId) {
        addFollowee(follower, followeeId);
    }
    else{
        addNewUser (obj, follower, followerId, followeeId);
    }
}

/*******************上面使用到的函数1*********************/
void addNewUser(Twitter* obj, USER *tail, int followerId, int followeeid)
{
    USER *new = (USER*)malloc(sizeof(USER));
    new->id = followerId;
    new->followee.id = 0;
    new->followee.next = NULL;
    if (tail == NULL){
        obj->usrlst = new;
    }
    else{
        tail->next = new;
    }
    addFollowee(new, followeeid);
}
void addFollowee(USER* follower, int followeeid)
{
    FOLLOWEE* find = &follower->followee;
    FOLLOWEE* add = (FOLLOWEE*)malloc(sizeof(FOLLOWEE));
    add->id = followeeid;
    add->next = NULL;
    while (find->next != NULL){
        find = find->next;
    }  
    find->next = add;
    return;
}
/*******************使用到的函数1结束*********************/

/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
void twitterUnfollow(Twitter* obj, int followerId, int followeeId) {
    USER* usr = obj->usrlst;
    while (usr != NULL) {
        if (usr->id == followerId) {
            delFollowee(usr, followeeId);
            return;
        }
        usr = usr->next;
    }
}
/*******************上面使用到的函数2*********************/
void delFollowee(USER *follower, int followeeid)
{
    FOLLOWEE *find = &follower->followee;
    while (find->next != NULL) {
        FOLLOWEE *next = find->next;
        if (next->id == followeeid){
            find->next = next->next;
            free(next);
            return;
        }
        find = find->next;
    }
}
/*******************使用到的函数2结束*********************/
void twitterFree(Twitter* obj) {
    NEWS *news = obj->newslst;
    USER *usr = obj->usrlst;
    while (news) {
        NEWS *tmp = news;
        news = news->next;
        free(tmp);
    }
    while (usr) {
        FOLLOWEE *del = usr->followee.id;
        while (del) {
            FOLLOWEE* tmp = del;
            del = del->next;
            free(tmp);
        }
        USER* tmp = usr;
        usr = usr->next;
        free(tmp);
    }
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
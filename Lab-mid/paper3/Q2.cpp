// Question 2: Complex Has-A Relationship (Composition) with Array of Pointers
// Concepts Tested: Has-A Relationship & Array of Objects (05), Fundamentals (03), this Keyword (04).
// Scenario: You are building the backend for a new Social Media Application tailored for Pakistan
// . The app revolves around Users, Posts, and Comments, requiring strict object association.
// Requirements:
// Comment Class: Contains content (string). Provide a method editContent(const string& newContent)
// .
// Post Class (Has-A Comment):
// Must contain title, content, and a dynamic array of pointers to comments (Comment* commentsArray) to aggregate comments
// .
// Use the this keyword in the Post constructor to resolve ambiguity between parameter names and member variables
// .
// Include an addComment(Comment* comment) function that links a newly created comment to the post, and a displayInfo() function
// .
// User Class (Has-A Post):
// Must contain userName, a unique integer userID, and an array of pointers to posts (Post* postsArray)
// .
// Include createPost(const string& title, const string& content) and addCommentToPost(Post* post, Comment* comment)
// 
// Execution: Create a user named "Shafique Rehman"
// . Have Shafique create two posts: "My Vacation Adventure" and "Homemade Dinner"
// . Add comments to these posts using dynamic memory (new Comment(...)), edit one of the comments, and display Shafique's entire feed showing the updated information
// .
#include <iostream>
using namespace std;
class Comment{
    private:
    string content;
    public:
    Comment(string content):content(content){}
    void editContent(const string& newContent){
        this->content = newContent;
    }
    string getContent() const {
        return content;
    }
};
class Post{
    private:
    string title;
    string content;
    Comment **commentArray;
    int commentCount;
    public:
    Post(string title, string content) {
        this->title = title;
        this->content = content;
        this->commentArray = nullptr;
        this->commentCount = 0;
    }
    void addComment(Comment* comment) {
        Comment** tempArray = new Comment*[commentCount + 1];
        for(int i = 0; i < commentCount; i++) {
            tempArray[i] = commentArray[i];
        }
        tempArray[commentCount] = comment;
        delete[] commentArray;
        commentArray = tempArray;
        commentCount++;
    }
    void displayInfo() const {
        cout << "Title: " << title << endl;
        cout << "Content: " << content << endl;
        cout << "Comments: " << commentCount << endl;
        for(int i = 0; i < commentCount; i++) {
            cout << "  - " << commentArray[i]->getContent() << endl;
        }
    }
    ~Post() {
        for (int i = 0; i < commentCount; i++) {
            delete commentArray[i];
        }
        delete[] commentArray;
    }
};

class User {
    private:
    string userName;
    int userID;
    Post **postsArray;
    int postCount;
    public:
    User(string userName, int userID) : userName(userName), userID(userID), postsArray(nullptr), postCount(0) {}
    void createPost(const string& title, const string& content) {
        Post** tempArray = new Post*[postCount + 1];
        for(int i = 0; i < postCount; i++) {
            tempArray[i] = postsArray[i];
        }
        tempArray[postCount] = new Post(title, content);
        delete[] postsArray;
        postsArray = tempArray;
        postCount++;
    }
    void addCommentToPost(int postIndex, Comment* comment) {
        if(postIndex >= 0 && postIndex < postCount) {
            postsArray[postIndex]->addComment(comment);
        }
    }
    void displayFeed() const {
        cout << "User: " << userName << " (ID: " << userID << ")" << endl;
        for(int i = 0; i < postCount; i++) {
            cout << "Post " << i+1 << ":" << endl;
            postsArray[i]->displayInfo();
            cout << endl;
        }
    }
    ~User() {
        for (int i = 0; i < postCount; i++) {
            delete postsArray[i];
        }
        delete[] postsArray;
    }
};
int main(){
    User shafique("Shafique Rehman", 1);
    
    shafique.createPost("My Vacation Adventure", "Had the best time on vacation!");
    shafique.createPost("Homemade Dinner", "Made a delicious home-cooked meal");
    
    shafique.addCommentToPost(0, new Comment("That sounds amazing!"));
    shafique.addCommentToPost(0, new Comment("I want to go there too!"));
    shafique.addCommentToPost(1, new Comment("Looks delicious!"));
    
    shafique.displayFeed();
    
    return 0;
}
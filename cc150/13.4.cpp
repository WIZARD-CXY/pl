#include <iostream>
#include <cstring>
using namespace std;

class MyString
{
private:
    char *m_pchString;
    int m_nLength;

    
 
public:
    MyString(char *pchString="")
    {
        // Find the length of the string
        // Plus one character for a terminator
        m_nLength = strlen(pchString) + 1;
        
        // Allocate a buffer equal to this length
        m_pchString= new char[m_nLength];
        
        // Copy the parameter into our internal buffer
        strncpy(m_pchString, pchString, m_nLength);
    
        // Make sure the string is terminated
        m_pchString[m_nLength-1] = '\0';
    }
 
    ~MyString() // destructor
    {
        // We need to deallocate our buffer
        delete[] m_pchString;
        cout<<"in destructor"<<endl;
 
        // Set m_pchString to null just in case
        m_pchString = 0;
    }
 
    char* GetString() { return m_pchString; }
    int GetLength() { return m_nLength; }

    // Copy constructor
    MyString(const MyString& cSource)
    {
    	cout<<"in copy constructor"<<endl;
    // because m_nLength is not a pointer, we can shallow copy it
	    m_nLength = cSource.m_nLength;
	 
	    // m_pchString is a pointer, so we need to deep copy it if it is non-null
	    if (cSource.m_pchString)
	    {
	        // allocate memory for our copy
	        m_pchString = new char[m_nLength];
	 
	        // Copy the string into our newly allocated memory
	        strncpy(m_pchString, cSource.m_pchString, m_nLength);
	    }
	    else
	        m_pchString = 0;
	}

	// Assignment operator
	MyString& operator=(const MyString& cSource)
	{
		cout<<"in operator="<<endl;
	    // check for self-assignment
	    if (this == &cSource)
	        return *this;
	 
	    // first we need to deallocate any value that this string is holding!
	    delete[] m_pchString;
	 
	    // because m_nLength is not a pointer, we can shallow copy it
	    m_nLength = cSource.m_nLength;
	 
	    // now we need to deep copy m_pchString
	    if (cSource.m_pchString)
	    {
	        // allocate memory for our copy
	        m_pchString = new char[m_nLength];
	 
	        // Copy the parameter the newly allocated memory
	        strncpy(m_pchString, cSource.m_pchString, m_nLength);
	    }
	    else
	        m_pchString = 0;
	 
	    return *this;
	}  

};

int main(){
	MyString cHello("Hello, world!");
	MyString cHello1("Hello, world!");
 
	{
	    MyString cCopy=cHello; // use default copy constructor
	} // cCopy goes out of scope here

	MyString cCopy2 = cHello;
	cCopy2 = cHello1;

 
    std::cout << cHello.GetString() << std::endl; // this will crash
}
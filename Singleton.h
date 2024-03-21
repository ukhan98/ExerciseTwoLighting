#ifndef SINGLETON_H       // If SINGLETON_H is not defined yet,
#define SINGLETON_H       // define SINGLETON_H to prevent multiple inclusions.

template <typename T>    // Declare a template class with type parameter T.
class Singleton
{
public:                  // Access specifier
    static T& GetInstance()  // Declare a static member function that returns a reference to an instance of type T.
    {
        static T instance;   // Declare a static variable 'instance' of type T. Initialized only once.
        return instance;     // Return a reference to it
    }

protected:               // Access specifier 
    Singleton() { }       // Protected constructor to prevent instantiation outside of the class.
    virtual ~Singleton() { }  // Protected virtual destructor to allow derived class destruction.

public:                  //public access specifier 
    Singleton(Singleton const&) = delete;        // Delete the copy constructor to prevent copying.
    Singleton& operator=(Singleton const&) = delete;  // Delete the copy assignment operator to prevent assignment.

};

#endif // SINGLETON_H    // End of the preprocessor conditional.


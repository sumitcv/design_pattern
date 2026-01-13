//----------------------------------------------------
// Single check locking 
static SingletonClass* getInstance()
{
	lock_guard<mutex> lock(mtx);
	if (instance == nullptr)
	{
		instance = new SingletonClass();    
	}
	return instance;
}

//----------------------------------------------------
// Single check locking 
static SingletonClass* getInstance()
{
	// Double-checked locking
	if (instance == nullptr)
	{
		lock_guard<mutex> lock(mtx);
		if (instance == nullptr)
		{
			instance = new SingletonClass();    
		}
	}
	return instance;
}

//--------------------------------------------------
// std::once_flag for thread-safe singleton. 
std::once_flag flag;
SingletonClass * getInstance()
{
	std::call_once(flag, []{
		instance = new SingletonClass;
});
return instance; 
}

//----------------------------------------------------
// Static variable are thread safe. 
SingletonClass& getInstance()
{
	static SingletonClass instance;
	return instance;
}

template<typename T>
class ObjectPool {
    public:
        ObjectPool(size_t size=32);
        virtual ~ObjectPool();

        void setPoolSize(size_t size);

        T* New();

        void Delete(T* p);

    private:
        std::queue
        size_t poolSize;
        queue<T> freePool;
        vector<T> occupyPool; 
}
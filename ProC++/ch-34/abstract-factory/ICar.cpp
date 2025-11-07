export class ICar
{
    public:
        virtual ~Icar = default; //Always a virtual destructor 
        virtual std::string info() const = 0;
};


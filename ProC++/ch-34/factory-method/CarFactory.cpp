export class CarFactory
{
public:
    virtual ~CarFactory()  = default;   //ALways a virtual destructor 
    //omitted deafulted, copy/move

    std::unique_ptr<Icar> requestCar()
    {
        //Increment the number of cars produced and return the new car
        ++m_numberOfCarsProduced;
        return createCar();
    }
}
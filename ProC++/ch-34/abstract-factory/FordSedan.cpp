export class FordSedan : public Ford
{
    public:
        std::string info() const override { return "Ford Sedan";}
};
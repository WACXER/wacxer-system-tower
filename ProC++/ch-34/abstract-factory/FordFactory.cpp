export class FordFactory : public ICarFactory
{
public:
     std::unique_ptr<Icar> makeSuv() const override {
        return {std::make_unique<FordSuv>(); }
     };
     std::unique_ptr<Icar> makeSedan() const override {
        return {std::make_unique<FordSedan>();}
     }
}

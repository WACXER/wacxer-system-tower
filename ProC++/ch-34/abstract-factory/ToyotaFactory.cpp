export class ToyotaFactory : ICarFactory
{
public:
    std::unique_ptr<ICar> makeSuv() const override {
        return {std::make_unique<ToyotaSuv>();}
    };
    std::unique_ptr<ICar> makeSedan() const override {
        return {std::make_unique<ToyotaSuv>();}
    }
}
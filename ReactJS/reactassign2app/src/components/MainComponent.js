import { superHeros } from "./Data";
import Card from "./Card";

const MainComponent = () => {
  return (
    <div className="container">
      {superHeros.map((superhero, key) => {
        return <Card key={key} superhero={superhero} />;
      })}
    </div>
  );
};
export default MainComponent;

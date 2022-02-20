import "./App.css";
import Model from "./components/Model";
import {superHeros} from "./components/Data";
import MainComponent from "./components/MainComponent";
import { BrowserRouter as Router, Routes, Route } from "react-router-dom";

function App() {
  return (
    <Router>
      <Routes>
      <Route path="/" element={<MainComponent />}></Route>
        {superHeros.map((superhero, key) => {
          return (
            <Route path={"/" + superhero.title} element={<Model superhero={superhero} />}/>
          );
        })}
      </Routes>
    </Router>
  );
}

export default App;

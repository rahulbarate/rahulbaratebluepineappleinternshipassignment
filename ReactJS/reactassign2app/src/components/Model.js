import "./Model.css";
import { Link } from "react-router-dom";

const Model = (props) => {
  const { title, src, text, abilities, appearance } = props.superhero;
  return (
    <>
      <div className="model">
        <Link to="/" className="back-btn">
          Back
        </Link>
        <div className="model-header">
          <img src={src} className="model-image"></img>
          <div className="model-titleandinfo-div">
            <h1 className="model-title">{title}</h1>
            <h3 className="model-title">First Appearance: {appearance}</h3>

            <h3 className="model-title">Abilities : </h3>
            <ul>
              {abilities.map((data, key) => {
                return <li key={key}>{data}</li>;
              })}
            </ul>
          </div>
        </div>
        <div className="model-body">
          <p className="model-text">{text}</p>
        </div>
      </div>
    </>
  );
};

export default Model;

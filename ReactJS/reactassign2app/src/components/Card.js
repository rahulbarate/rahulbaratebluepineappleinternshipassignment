import "./Card.css";
import {Link} from "react-router-dom";

const Card = (props) => {
    const {src,title,text} = props.superhero;

  return (
    <Link to={"/"+title}>
      <div className="card">
          <img className="card-image" src={src}></img>
          <h2 className="card-title">{title}</h2>
          <p className="card-text">{text}</p>
      </div>
    </Link>
  );
};
export default Card;

// --------- BOILERPLATE -----------------------------------------------------
// const _l = (msg) => console.log("Output ==> [" + msg + "]");
// --------- BOILERPLATE -----------------------------------------------------


//------pass functions as arguments

function sayHello() {
  return "Hello, ";
}

function sayBye() {
  return "Bye, ";
}

//

function greeting(/*function*/greetMessage, /*string*/name) {
  console.log(greetMessage() + name);
}

// Pass `sayHello` as an argument to `greeting` function
greeting(sayHello, "Lovely folks!"); //separating out console io from computation

greeting(sayBye, "All of You!"); //separating out console io from computation

const names = ['Namrata', 'Rishikesh', 'Anupama', 'Madhavan'];

//TODO - for every one in names, say hello and Bye
names.forEach((val) => {
  greeting(sayHello, val);
  greeting(sayBye, val);
  console.log("------");
})

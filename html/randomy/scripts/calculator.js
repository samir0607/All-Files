let result = localStorage.getItem('result') || '';

output();

function input(value){
  result += value;
  output();
  localStorage.setItem('result', result);
}
function output(){
  document.querySelector('.js-display').innerHTML = result;
}
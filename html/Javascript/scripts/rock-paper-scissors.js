let score = JSON.parse(localStorage.getItem('score'))
    if(!score){
      score = {
        wins: 0,
        losses: 0,
        ties: 0
      };
    }

    updateScore();

    document.querySelector('.js-rock-button')
      .addEventListener('click', () => {
        playGame('rock');
      });
    document.querySelector('.js-paper-button')
    .addEventListener('click', () => {
      playGame('paper');
    });
    document.querySelector('.js-scissors-button')
    .addEventListener('click', () => {
      playGame('scissors');
    });

    document.querySelector('.js-reset-button')
      .addEventListener('click', () => {
        score.wins = score.losses = score.ties = 0;
        localStorage.removeItem('score');
        updateScore();
      });

    document.querySelector('.js-auto-play-button')
    .addEventListener('click', () => {
      autoPlay();
    });

    document.body.addEventListener('keydown', (event) => {
      if(event.key === 'r'){
        playGame('rock');
      } else if(event.key === 'p'){
        playGame('paper');
      } else if(event.key === 's'){
        playGame('scissors');
      }
    });
    function playGame(playerMove){
      const computerMove = pickComputerMove();

      console.log(computerMove);
      let result = '';
      if(playerMove === 'paper'){
        if(computerMove === 'rock'){
          result = 'You win';
        }else if(computerMove === 'paper'){
          result = 'Tie';
        }else if(computerMove === 'scissors'){
          result = 'You lose';
        }
      } else if(playerMove === 'rock'){
        if(computerMove === 'rock'){
          result = 'Tie';
        }else if(computerMove === 'paper'){
          result = 'You lose';
        }else if(computerMove === 'scissors'){
          result = 'You win';
        }
      } else if(playerMove === 'scissors'){
        if(computerMove === 'rock'){
          result = 'You lose';
        }else if(computerMove === 'paper'){
          result = 'You win';
        }else if(computerMove === 'scissors'){
          result = 'Tie';
        }
      }
      if(result === 'You win'){
        score.wins += 1;
      } else if(result === 'You lose'){
        score.losses += 1;
      } else if(result === 'Tie'){
        score.ties += 1;
      }

      localStorage.setItem('score', JSON.stringify(score));
      
      updateScore();

      document.querySelector('.js-result')
        .innerHTML = `${result}`;

      document.querySelector('.js-moves')
        .innerHTML = `You 
        <img src="images/${playerMove}-emoji.png" class="move-icon">
        <img src="images/${computerMove}-emoji.png" class="move-icon"> 
        Computer`;
    }
    function updateScore(){
      document.querySelector('.js-score')
      .innerHTML = `Wins: ${score.wins}, Losses: ${score.losses}, Ties: ${score.ties}`;
    }

    function pickComputerMove(){
        const randomNumber = Math.random();
        let computerMove = '';
        if(randomNumber >= 0 && randomNumber < 1/3){
          computerMove = 'rock';
        }else if(randomNumber < 2/3){
          computerMove = 'paper';
        }else{
          computerMove = 'scissors';
        }
        return computerMove;
    }
    let isAutoPlaying = false;
    let intervalID;
    function autoPlay(){
      if(!isAutoPlaying){
        intervalID = setInterval(function(){
          const playerMove = pickComputerMove();
          playGame(playerMove);
        }, 500);
        isAutoPlaying = true;
      } else{
        clearInterval(intervalID);
        isAutoPlaying = false;
      }
    }
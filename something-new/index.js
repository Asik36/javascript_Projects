document.addEventListener('keyup', function(event) {
    switch(event.keyCode){
        case 87: // w key
            document.getElementById("dot_up").style.background =
                 'rgb(' + 0 + ',' + 125 + ',' + 240 + ')';
            break;
        case 65: // a key
            document.getElementById("dot_left").style.background =
                 'rgb(' + 0 + ',' + 125 + ',' + 240 + ')';
            break;
        case 83: // s key
            document.getElementById("dot_down").style.background =
                 'rgb(' + 0 + ',' + 125 + ',' + 240 + ')';
            break;
        case 68: // d key
            document.getElementById("dot_right").style.background =
                 'rgb(' + 0 + ',' + 125 + ',' + 240 + ')';
            break;
        case 32: // space_bar key
            document.getElementById("space_bar").style.borderColor =
                 'rgb(' + 0 + ',' + 125 + ',' + 240 + ')';
            break;
        }       
    }
);
document.addEventListener('keydown', function(event) {
      if (event.repeat) return;
    switch(event.keyCode){
        case 87: // w key
            if(bool_up){
                noteHit("dot_up");
            } else{
                noteMiss("dot_up");
            }
        break;
        
        case 65: // a key
            document.getElementById("dot_left").style.background = "red";
            if(bool_right){
                hit.cloneNode(true).play();
            } else{
                miss.cloneNode(true).play();
            }
            break;
        break;
        case 83: // s key
            document.getElementById("dot_down").style.background = "red";
            if(bool_down){
                hit.cloneNode(true).play();
            } else{
                miss.cloneNode(true).play();
            }
            break;
        break;
        case 68: // d key
        document.getElementById("dot_right").style.background = "red";
        if(bool_left){
            hit.cloneNode(true).play();
        } else{
            miss.cloneNode(true).play();
        }
        break;
        
        break;
        case 32: // space_bar key
        document.getElementById("space_bar").style.borderColor = "red";
        if(bool_space){
            snd.play().cloneNode(true).play();
        } else{
            miss.cloneNode(true).play();
        }
        break;
    }
});





var bool_left, bool_right, bool_up, bool_down,bool_space = false;
var color_left, color_right, color_up, color_down, color_space = "blue";
var hit = new Audio("hit.wav"); // buffers automatically when created
var miss = new Audio("hit2.wav"); // buffers automatically when created






function noteMiss(dot) {
    miss.cloneNode(true).play();
    document.getElementById(dot).style.background = "red";
}

function noteHit(dot) {
    hit.cloneNode(true).play();
    document.getElementById(dot).style.background = "green";
}

function noteUp(sec){
    var elem = newNote("up", sec);
    startAnimation("up", sec,elem);

    elem.addEventListener('animationend', () => {
        elem.remove();
        bool_up = false;
    });
}
function noteLeft(sec){
    var elem = newNote("left", sec);
    startAnimation("left", sec,elem);
    elem.addEventListener('animationend', () => {
        elem.remove();
        bool_left = false;
    });
}
function noteRight(sec){
    var elem = newNote("right", sec);
    startAnimation("right", sec,elem);
    elem.addEventListener('animationend', () => {
        elem.remove();
        bool_right = false;
    });
}
function noteDown(sec){
    var elem = newNote("down", sec);
    startAnimation("down", sec,elem);
    elem.addEventListener('animationend', () => {
        elem.remove();
        bool_down = false;
    });
}






function startAnimation(dirc,sec,elem){
    switch(dirc){
        case 'left':
            setTimeout(() =>{bool_left=true},sec*1000-500);
        case 'right':
            setTimeout(() =>{bool_right=true},sec*1000-500);
        case 'up':
            setTimeout(() =>{bool_up=true},sec*1000-500);
        case 'down':
            setTimeout(() =>{bool_down=true},sec*1000-500);

    }
    elem.style.animation = dirc+" "+sec+"s linear";
    setTimeout(() =>{bool_up=true},sec*1000-100);
    console.log(sec*1000);
}

function newNote(dirc){
    var elem = document.createElement("div");
    elem.classList.add("Note");
    document.getElementById('dot_'+dirc).append(elem);
    return elem;
}
noteUp(1.6);
noteUp(1.4);
noteUp(1.2);
noteUp(1.0);

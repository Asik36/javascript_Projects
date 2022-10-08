import Note from './Note.js';
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
            if(bool_left){
                noteHit("dot_left");
            } else{
                noteMiss("dot_left");
            }
            break;
        break;
        case 83: // s key
            if(bool_down){
                noteHit("dot_down");
            } else{
                noteMiss("dot_down");
            }
            break;
        break;
        case 68: // d key
        if(bool_right){
            noteHit("dot_right");
            } else{
                noteMiss("dot_right");
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
var time;
function song(){
    time = 0;
    setInterval(() => {time = time+10;},10);
    new Note("up",1.2,3);
    new Note("left",1,3.2);
    new Note("down",1,3.4);
    new Note("right",1,3.6);
    new Note("up",1,3.8);
    new Note("left",1,4);
    new Note("down",1,4.2);
    new Note("right",1,4.4);

}

song();



    


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
const arrUp = [];
const arrLeft = [];
const arrRight = [];
const arrDown = [];

document.addEventListener('keydown', function(event) {
      if (event.repeat) return;
    var note = null;
    switch(event.keyCode){
        case 87: // w key
            note = CheckHitWindow({arr: arrUp});
            if(note != null){
                    noteHit("dot_up",note);
                    note = null;
                } else{
                    noteMiss("dot_up");
                }
            break;
        
        case 65: // a key
            note = CheckHitWindow({arr: arrLeft});

            if(note != null){
                noteHit("dot_left",note);
                note = null;
            } else{
                noteMiss("dot_left");
            }
            break;
        case 83: // s key
            note = CheckHitWindow({arr: arrDown});

            if(note != null){
                noteHit("dot_down",note);
                note = null;
            } else{
                noteMiss("dot_down");
            }
            break;
        case 68: // d key
            note = CheckHitWindow({arr: arrRight});
            if(note != null){
                noteHit("dot_right",note);
                note = null;
            } else{
                noteMiss("dot_right");
            }
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


function CheckHitWindow(obj) {
    var arr = obj.arr;
    for (let index = 0; index < arr.length; index++) {
        var func = arr[index]();
        if (func[0]) {
            return func[1];
        }
    }
    return null;
}

function noteMiss(dot) {
    miss.cloneNode(true).play();
    document.getElementById(dot).style.background = "red";
}

function noteHit(dot,note) {
    note.remove();
    hit.cloneNode(true).play();
    document.getElementById(dot).style.background = "green";
    console.log("HIT!")
    
}

function newNote(dirc,speed,delay){
    setTimeout(()=>{
    var note = new Note(dirc,speed);
    newHitWindow(note);
    },(delay-speed)*1000);
}


function newHitWindow(note){
    var arr;
    switch(note.dirc){
        case("up"):
        arr = arrUp;
        break;
        case("left"):
        arr = arrLeft;
        break;
        case("right"):
        arr = arrRight;
        break;
        case("down"): 
        arr = arrDown;
        break; 
    }
    arr.push(function() {
        console.log("correct time is ", note.startTime + note.runningTime-note.newTime," while current time is ",Date.now());
        if((Date.now() > (note.startTime + note.newTime)) && (Date.now() < (note.startTime + note.runningTime))){
            return [true, note];
        }
        return [false, null];
    });
    
        
}
function song(){
    newNote("up",1,3);
    newNote("up",1,4);
    newNote("up",1,5);
    newNote("right",1,3);
    newNote("right",1,4);
    newNote("right",1,5);
    



}
function remove(el) {
    var element = el;
    element.remove();
    song();

  }
  
document.getElementById('btn_start').addEventListener('click', ()=>(remove(document.getElementById('btn_start'))));
var hit = new Audio("hit.wav"); // buffers automatically when created
var miss = new Audio("hit2.wav"); // buffers automatically when created





    


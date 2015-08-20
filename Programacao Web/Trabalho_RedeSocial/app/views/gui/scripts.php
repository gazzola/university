<script type="text/javascript" src="scripts/pngFix/jquery.pngFix.js"></script>
<link rel="stylesheet" type="text/css" href="scripts/tipsy.css" />
<script type="text/javascript" src="scripts/tipsy.js"></script>

<script type="text/javascript">
$(document).ready(function(){

    $(document).pngFix(); 
	$(".tooltip").tipsy({
		delayIn: 0,
		delayOut: 0,
		fade: true,
		fallback: '',
		gravity: $.fn.tipsy.attrGV,
		html: true,
		live: true,
		offset: 0,
		opacity: 1,
		title: 'title',
		trigger: 'hover'
	});
	
});
</script>
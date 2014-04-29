<div id="popupmessage" style="background-color:<?php echo $popupbgcolor;?>">
	<?php echo $popupmessage;?><br><br>
	<input type="button" value="OK" onClick="Popup.hide('popupmessage')">
</div>
<script type="text/javascript">
Popup.showModal('popupmessage',null,null,{'screenColor':'rgb(229, 229, 229)','screenOpacity':.8});
</script>

<script type="text/javascript" src="js/ckeditor/ckeditor.js" ></script>
<div class="box">
    <div class="box-header bg-green">
        <h3 class="box-title">Welcome message for feedback page</h3>
        <div class="box-tools">
            <button class="sm-btn bg-green" data-widget="collapse">-</button>
        </div>
    </div>
    <div class="box-body">
        <?php $feedback = get_page_data("feedback");?>
            <form>
                <textarea id="feedbackeditor" name="feedbackeditor">
                    <?php echo $feedback['content']; ?>
                </textarea>
                <input type="button" value="Update" onclick="updatefeedback()"/>
            </form>        
    </div><!-- /.box-body -->

</div>
<div class="box">
    <div class="box-header bg-green">
        <h3 class="box-title">Announcements for promotion</h3>
        <div class="box-tools">
            <button class="sm-btn bg-green" data-widget="collapse">-</button>
        </div>
    </div>
    <div class="box-body">
	Header : <input type="text" class="wide" name="promotionheader" value="<?php $promotion = get_page_data('promotion'); $promotion['title']?> " />
            <form>
                <textarea id="promotioneditor" name="promotioneditor">
                    <?php echo $promotion['content'] ;?>
                </textarea>
                <input type="button" value="Update" onclick="updatepromotion()"/>               
            </form>        

    </div><!-- /.box-body -->
</div>

<script type="text/javascript">
$("[data-widget='collapse']").click(function() {
	var box = $(this).parents(".box").first();
        //Find the body and the footer
        var bf = box.find(".box-body, .box-footer");
        if (!box.hasClass("collapsed-box")) {
            box.addClass("collapsed-box");
			var w = $('#wrapper').width();
            bf.slideUp();
			box.width(w);
			
        } else {
            box.removeClass("collapsed-box");
            bf.slideDown();
        }
	});
CKEDITOR.replace('feedbackeditor');	
CKEDITOR.replace('promotioneditor');
function updatefeedback(){
	$('#feedbackeditor').parent().parent().parent().append( "<div class='overlay' id='overlay1'></div><div class='loading-img' id='loading1'></div>");
	$.ajax({
		url: "backend.php",  
		type: "POST",
		data: {FeedbackEdited:true,text:CKEDITOR.instances['feedbackeditor'].getData()},    
		cache: false,
		success: function(data) {
				CKEDITOR.instances['feedbackeditor'].setData(data);
				$('#overlay1').remove();
				$('#loading1').remove();
			}
		});
}
</script>
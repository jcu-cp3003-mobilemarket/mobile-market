<?php
@require_once("databaseconnect.inc");
$events = get_event_data();
?>
<div>
<!-- THE CALENDAR -->
<div class="box max-300px" >
    <div class="box-header bg-aqua">
        <h4 class="box-title">Draggable Events</h4>
    </div>
    <div class="box-body">
        <!-- the events -->
        <div id='external-events'>                                        
            <div class='external-event bg-green'>Lunch</div>
            <div class='external-event bg-red'>Go home</div>
            <div class='external-event bg-aqua'>Do homework</div>
            <div class='external-event bg-yellow'>Work on UI design</div>
            <div class='external-event bg-navy'>Sleep tight</div>
            <p>
                <input type='checkbox' id='drop-remove' /> <label for='drop-remove'>remove after drop</label>
            </p>
        </div>
    </div>
</div>
<div id="calendar"></div>

<div class="box max-300px">
    <div class="box-header bg-maroon">
        <h3 class="box-title">Create Event</h3>
    </div>
    <div class="box-body">
            <div id="color-chooser-btn">Color <span class="arrow-symbool">&#x25bc;</span></div>
            <ul class="dropdown-menu ishiding" id="color-chooser">
                <li class="text-green" >&#x2588;<a class="text-green" href="#"> Green</a></li>
                <li class="text-blue">&#x2588;<a class="text-blue" href="#"> Blue</a></li>                                            
                <li class="text-navy">&#x2588;<a class="text-navy" href="#"> Navy</a></li>                                            
                <li class="text-yellow">&#x2588;<a class="text-yellow" href="#"> Yellow</a></li>
                <li class="text-orange">&#x2588;<a class="text-orange" href="#"> Orange</a></li>
                <li class="text-aqua">&#x2588;<a class="text-aqua" href="#"> Aqua</a></li>
                <li class="text-red">&#x2588;<a class="text-red" href="#"> Red</a></li>
                <li class="text-purple">&#x2588;<a class="text-purple" href="#"> Purple</a></li>
                <li class="text-maroon">&#x2588;<a class="text-maroon" href="#"> Maroon</a></li>
            </ul>
        <div class="input-group">                                          
            <input id="new-event-title" type="text" class="form-control" placeholder="Event Title" style="padding:20px;" />&nbsp;
            <input type="button" id="add-new-event" value="Add" class="btn btn-default btn-flat" />
        </div><!-- /input-group -->
    </div>
</div>        

<script src="js/fullcalendar/fullcalendar.min.js" type="text/javascript"></script>
<script type="text/javascript">
$('#color-chooser-btn').click(
	function(){
		if($('.dropdown-menu').hasClass('ishiding')){
			$('.dropdown-menu').slideDown();
			$('.dropdown-menu').removeClass('ishiding');
			$('.arrow-symbool').html('&#x25b2;');
		}
		else{
			$('.dropdown-menu').slideUp();
			$('.dropdown-menu').addClass('ishiding');
			$('.arrow-symbool').html('&#x25bc;');
		}
	});
		
            $(function() {
				$('.dropdown-menu').slideUp();
                /* initialize the external events
                 -----------------------------------------------------------------*/
                function ini_events(element) {
                    element.each(function() {
                        // create an Event Object (http://arshaw.com/fullcalendar/docs/event_data/Event_Object/)
                        // it doesn't need to have a start or end
                        var eventObject = {
                            title: $.trim($(this).text()) // use the element's text as the event title
                        };

                        // store the Event Object in the DOM element so we can get to it later
                        $(this).data('eventObject', eventObject);

                        // make the event draggable using jQuery UI
                        $(this).draggable({
                            zIndex: 1000,
                            revert: true, // will cause the event to go back to its
                            revertDuration: 0  //  original position after the drag
                        });

                    });
                }
                ini_events($('#external-events div.external-event'));

                /* initialize the calendar
                 -----------------------------------------------------------------*/
                //Date for the calendar events (dummy data)
                var date = new Date();
                var d = date.getDate(),
                        m = date.getMonth(),
                        y = date.getFullYear();
                var calendar = $('#calendar').fullCalendar({
                    header: {
                        left: 'prev,next today',
                        center: 'title',
                        right: 'month,agendaWeek,agendaDay'
                    },
                    buttonText: {//This is to add icons to the visible buttons
                        prev: "&#x25c0;",
                        next: "&#x25b6;",
                        today: 'today',
                        month: 'month',
                        week: 'week',
                        day: 'day'
                    },
					selectable :true,
                    //Random default events
                    events: [
					<?php for($i = 0;$i<count($events);$i++){ ?>
                        {
							id:'<?php echo $events[$i]['id']?>',
                            title: '<?php echo $events[$i]['title']?>',
                            start: new Date("<?php echo $events[$i]['start'];?>"),
                            end: new Date("<?php echo $events[$i]['end'];?>"),
							allDay:<?php echo $events[$i]['allday']?>,
                            backgroundColor: "<?php echo $events[$i]['color']?>", //yellow
                            borderColor: "<?php echo $events[$i]['color']?>" //yellow
                        }
					<?php 
						if($i+1 != count($events)){echo ",";}
						}
					?>
                    ],
                    editable: true,
                    droppable: true, // this allows things to be dropped onto the calendar !!!
                    drop: function(date, allDay) { // this function is called when something is dropped
                        // retrieve the dropped element's stored Event Object
                        var originalEventObject = $(this).data('eventObject');
                        // we need to copy it, so that multiple events don't have a reference to the same object
                        var copiedEventObject = $.extend({}, originalEventObject);
						var id = randID(5);
                        // assign it the date that was reported
                        copiedEventObject.start = date;
                        copiedEventObject.allDay = allDay;
                        copiedEventObject.backgroundColor = $(this).css("background-color");
                        copiedEventObject.borderColor = $(this).css("background-color");
						copiedEventObject.id = id;
							
                        // render the event on the calendar
                        // the last `true` argument determines if the event "sticks" (http://arshaw.com/fullcalendar/docs/event_rendering/renderEvent/)
						$.ajax({
							url:"backend.php",
							type:"post",
							cache:false,
							data:{
							EventObjectSubmitted:true,
							add:true,
							id:id,
							start:copiedEventObject.start,
							end:copiedEventObject.start,
							allday:true,
							title:copiedEventObject.title,
							color:$(this).css("background-color")
							},
							success: function(data){
								$('#calendar').fullCalendar('renderEvent', copiedEventObject, true);
								}
							});
                        // is the "remove after drop" checkbox checked?
                        if ($('#drop-remove').is(':checked')) {
                            // if so, remove the element from the "Draggable Events" list
                            $(this).remove();
                        }
                    },
					eventDragStart: function( event, jsEvent, ui, view ) { 
						dragged = [ ui.helper[0], event ];
					},
					eventDragStop: function(event, jsEvent, ui, view) { 
						if (isElemOverDiv(ui, $('#calendarTrash'))) {
							var con = confirm("Are you sure want to remove '"+event.title+"'?");
							if(con){
								calendar.fullCalendar('removeEvents', event.id);
							}
						}
					},
					eventDrop:function( event, dayDelta, minuteDelta, allDay, revertFunc, jsEvent, ui, view ) { 
						$.ajax({
							url:"backend.php",
							type:"post",
							cache:false,
							data:{
							EventObjectSubmitted:true,
							update:true,
							id:event.id,
							start:event.start,
							end:event.end,
							allday:event.allDay,
							},
							success: function(data){
								$('#calendar').fullCalendar('renderEvent', copiedEventObject, true);
								}
							});
					},
					eventResize: function(event,dayDelta,minuteDelta,revertFunc) {
							$.ajax({
							url:"backend.php",
							type:"post",
							cache:false,
							data:{
							EventObjectSubmitted:true,
							update:true,
							id:event.id,
							start:event.start,
							end:event.end,
							allday:event.allDay,
							},
							success: function(data){
								$('#calendar').fullCalendar('renderEvent', copiedEventObject, true);
								}
							});
						}
                });
                /* ADDING EVENTS */
                var currColor = "#f56954"; //Red by default
                //Color chooser button
                var colorChooser = $("#color-chooser-btn");
                $("#color-chooser > li > a").click(function(e) {
                    e.preventDefault();
                    //Save color
                    currColor = $(this).css("color");
                    //Add color effect to button
                    colorChooser.html($(this).text());
					colorChooser.css('background-color',currColor);
					$('.dropdown-menu').slideUp();
					$('.dropdown-menu').addClass('ishiding');
					colorChooser.append(' <span class="arrow-symbool">&#x25bc;</span>');
                });
                $("#add-new-event").click(function(e) {
                    e.preventDefault();
                    //Get value and make sure it is not null
                    var titleval = $("#new-event-title").val();
                    if (titleval.length == 0) {
                        return;
                    }
                    //Create event
                    var event = $("<div />");
                    event.css({"background-color": currColor, "border-color": currColor, "color": "#rgb(56,56,56)"}).addClass("external-event");
                    event.html(titleval);
                    $('#external-events').prepend(event);
                    //Add draggable funtionality
                    ini_events(event);
                    //Remove event from text input
                    $("#new-event-title").val("");
                });
				function randID(n)
					{
						var text = '';
						var possible = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789';
						for(var i=0; i < n; i++)
						{
							text += possible.charAt(Math.floor(Math.random() * possible.length));
						}				
						return text;
					}
				$('.fc-header-left').prepend('<span id="calendarTrash" class="calendar-trash"><img src="images/cal-trash.png"/></span>');
var isElemOverDiv = function(draggedItem, dropArea) {
        var dragged = $(draggedItem)[0].offset;

        var b = $(dropArea);
        var limitX = parseInt(b.offset().left) + parseInt(b.outerWidth());
        var limitY = parseInt(b.offset().top) + parseInt(b.outerHeight());

        // Compare
        if ( limitY >=   parseInt(dragged.top) 
            && limitX >=   parseInt(dragged.left) ) 
        { 
            return true; 
        }
        return false;
    }

            });
        </script>
</div>
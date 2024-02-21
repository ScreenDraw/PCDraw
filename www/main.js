(()=>{

    let ws    = new WebSocket( window.origin.replace("http://","ws://") );

    app.addEvent( $("[screen]"), "touchend", ( ev )=>{
        ws.send(`?cmd=MSE&p=0\n`);
    });

    app.addEvent( $("[screen]"), "touchstart", ( ev )=>{
        setTimeout(()=>{
            ws.send(`?cmd=MSE&p=1\n`);
        }, 100 );
    });

    app.addEvent( $("[screen]"), "touchmove", ( ev )=>{
        act = [ 
            ( ev.touches[0].clientX * 100 / ev.target.offsetWidth  ).toFixed(4), 
            ( ev.touches[0].clientY * 100 / ev.target.offsetHeight ).toFixed(4) 
        ];    ws.send( `?cmd=MSE&x=${act[0]}&y=${act[1]}\n` );
    });

})();
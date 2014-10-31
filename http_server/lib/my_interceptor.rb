class MyInterceptor
  def initialize(app)  
    @app = app  
  end  
    
  def call(env)  
    status, headers, response = @app.call(env)
    #byebug   
  end	
end 